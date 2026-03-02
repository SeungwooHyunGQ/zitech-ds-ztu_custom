# DS-ZTU 도어센서 개발 레퍼런스

## 디바이스 정보

| 항목 | 값 |
|------|-----|
| Model ID | TS0203 |
| Manufacturer Name | _GQ0001_gt633gvc |

---

## 특이사항 / 트러블슈팅

### 1. 페어링 모드에서 light_blink_start() 호출 시 Beacon Request 전송 중단

**증상:**
- 공장초기 상태 부팅 시 `zbdemo_bdbInitCb()`에서 `light_blink_start()`를 호출하면,
  Beacon Request가 1회만 전송되고 이후 반복 전송이 멈춤
- `light_blink_start()` 호출을 주석처리하면 약 5초 간격으로 정상 반복 전송됨

**재현 조건:**
- `PM_ENABLE = 1` (슬립 활성화 상태)
- `zbdemo_bdbInitCb()`의 factory-new 분기에서 `light_blink_start()` 호출
- `light_blink_start(0, 500, 500)` (무한) 및 `light_blink_start(60, 500, 500)` (유한) 모두 동일 증상

**추정 원인:**
- `light_blink_start()`가 내부적으로 `TL_ZB_TIMER_SCHEDULE()`로 타이머를 등록
- 이 타이머가 BDB의 network steering 타이머와 충돌하거나, 스택 내부의 슬립/타이머 스케줄링에 영향을 주는 것으로 추정
- `bdb_isIdle()` == true 구간에서 `drv_pm_lowPowerEnter()` 슬립 진입과의 상호작용 가능성도 있음

**현재 상태:**
- 페어링 모드 LED blink 호출 주석처리 상태
- 해결 방안 검토 필요

---

## 하드웨어 설정

| 항목 | 핀 | 활성 레벨 |
|------|-----|-----------|
| 네트워크 LED | PD3 | Active High (LED_ON=1, LED_OFF=0) |
| 스캔 키 (페어링/리셋) | PC0 | Falling Edge (풀업 10K) |
| 도어 센서 알람 | PD7 | Active High (풀다운 100K) |
| 탬퍼 감지 | PC1 | Active High (풀다운 100K) |

## 슬립 (PM) 관련

- `PM_ENABLE = 1`로 슬립 활성화
- 슬립 진입 조건: `bdb_isIdle()` && `!keyPressed` (`sampleSensor.c: app_task()`)
- 웨이크업 소스: PC0(키, LOW), PD7(알람, HIGH), PC1(탬퍼, HIGH)
- 페어링 모드 중에도 BDB idle 구간에서 슬립 진입 가능 → 타이머 동작에 영향
