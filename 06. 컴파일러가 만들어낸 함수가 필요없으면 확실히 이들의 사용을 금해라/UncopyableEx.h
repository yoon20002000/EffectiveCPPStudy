// C++ 98/03
class UncopyableEx
{
protected:              // 파생된 객체에 대해 생성과 소멸을 허용함.
    UncopyableEx(){}
    ~UncopyableEx(){}
private:
    UncopyableEx(const UncopyableEx&);          // 하지만 복사는 방지
    UncopyableEx& operator=(const UncopyableEx&);
}


class HomeForSale : private UncopyableEx // 복사생성자, 복사대입자는 선언 불가
{
}

// C++ 11 이상
class UncopyableEx
{
protected:              // 파생된 객체에 대해 생성과 소멸을 허용함.
    UncopyableEx(){}
    ~UncopyableEx(){}
    UncopyableEx(const UncopyableEx&) = delete;          // 하지만 복사는 방지
    UncopyableEx& operator=(const UncopyableEx&) = delete;
}