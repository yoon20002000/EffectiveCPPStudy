// 매크로 함수의 문제점

// a와 b중 큰 것을 f에 넘겨 호출
#define CALL_WITH_MAX(a,b) f((a) > (b) ? (a) : (b))

int a = 5, b = 0;

//  a가 사실상 ++a이 되기 때문에 비교문과 return a 에 두번 호출
// f((a) > (b) ? (a) : (b))
CALL_WITH_MAX(++a, b);  // a 두번 증가

// a가 a++이고, b가 b+10 b + 10
// 여기서 10이 더 크기 때문에 a는 비교문에서 한 번만 호출 돼 한 번만 증가
// f((a) > (b) ? (a) : (b))
CALL_WITH_MAX(++a, b + 10); // a 한 번 증가

// 직관적이지 못한 코드가 생성 됨.

// 반면 inline 함수에 대한 템플릿은 매크로 함수의 효율은 그대로 유지하며
// 정규 함수의 모든 동작 방식 및 타입 안전성까지 완벽히 활용

template <typename T>
inline void callWithMax(const T& a, const T&b)
{
    f( a > b ? a : b );
}

// T 가 정확히 무슨 타입인지 모르기에
// 매개변수로 상수 객체에 대한 참조자를 사용

// f 함수는 정의 돼 있어야 됨.