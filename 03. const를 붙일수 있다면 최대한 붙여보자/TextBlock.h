// const를 붙여 선언하면 컴파일러가 사용상의 에러를 잡는데 도움 됨
// const는 어떤 유효범위에있는 객체에도 붙을 수 있으며, 함수 매개 변수 및 반환 타입에도 적용 가능
// 멤버 함수에도 적용 가능

// 컴파일러에서는 비트수준 상수성을 지켜야 되지만, 프로그래머 개념적인(논리적) 상수성을 사용해서 프로그래밍 해야 됨
// 비트수준 상수성 : 어떤 객체의 멤버 함수가 객체의 정적 멤버를 제외한 데이터 멤버를 건드리지 않는 경우 const로 인정
// 개념적 상수성 : 상수 멤버 함수도 객체의 일부 몇 비트를 바꿀 수 있되 사용자 측에서 알아채지 못하도록(객체의 상태 영향을 주지 않도록) 해야 됨.

// 상수 멤버 및 비상수 멤버 함수가 기능적으로 서로 똑같게 구현되어 있을 경우 코드 중복을 피하는것이 좋음.
// 비상수 버전이 상수 버전을 호출하도록 적용

class TextBlock
{
public:
    const char& operator[](std::size_t position) const
    {
        /// ...
        /// 
        return text[position];
    }

    char& operator[](std::size_t position)
    {
        return
        const_cast<char&>(
            // 명확하게 const 참조를 한다고 해야 됨
            // 하지 않을 경우 비 const 참조이기 때문에 무한 재귀
            static_cast<const TextBlock&>(*this)[position]);
    }

private:
    char* text;
};