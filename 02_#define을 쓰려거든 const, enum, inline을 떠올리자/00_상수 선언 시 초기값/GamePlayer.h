// 단순한 상수를 쓸 때는, #define 보다 const 객체 혹은 enum을 우선 생각하자.
// 정수형 정적 상수 멤버의 선언 방법
class GamePlayer
{
private:
    static const int NumTurns = 5; // 상수 선언
    int scores[NumTurns]; // 상수 사용 예
};

// NumTurns는 '선언(declaration)' 된 것
// 정의 된것이 아님.

// 보통 정의가 돼야 하지만 정적 멤버로 만들어진 primitive 변수 타입의 클래스 내부 상수는 예외
// 일부의 경우 정의를 해 달라는 경우가 있는데 아래와 같이 정의 하면 된다

// CPP에 const int GamePlayer::NumTurns; 구현 됨

// 상수 정의는 cpp 파일에 둔다.

// 정의에는 상수의 초기값이 있으면 안된다.
// 클래스 상수의 초기값은 해당 상수가 선언된 시점에서 바로 주어기지 때문이다.