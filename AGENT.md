# AGENT.md - 프로젝트 규칙

## 언어
- 모든 대화는 한국어로 진행할 것
- git commit 메시지도 한국어로 작성할 것

## 개발 범위
- 이 프로젝트는 `apps/sampleContactSensor`만 개발 대상임
- 다른 예제(apps/ 하위)는 참고용으로만 활용하며 코드 수정 불필요
- `platform/common`은 개발 범위에 포함 (수정 가능)

## Target
- Chipset: TLSR8258 (1M Flash)

## 하드웨어 GPIO 매핑 (도어센서)

| 기능 | 핀 | 활성 레벨 | 비고 |
|------|-----|-----------|------|
| 센서 알람 (도어 감지) | PD7 | HIGH | 메인 리드스위치 |
| 탬퍼 감지 | PC1 | HIGH | 케이스 열림 감지 |
| 네트워크 LED | PD3 | LOW | 네트워크 상태 표시 |
| 스캔 키 (스티어링) | PC0 | Falling Edge | 네트워크 조인/리셋 버튼 |
