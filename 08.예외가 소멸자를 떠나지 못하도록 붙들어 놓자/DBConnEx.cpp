// close에서 예외가 발생하면 프로그램을 바로 끝냄. 
DBConn::~DBConn()
{
    try
    {
        db.close();
    }
    catch (...)
    {
        // Log : close 실패
        std::abort();
    }
}
// 에러가 발생한 후에 프로그램 실행을 계속할 수 없는 상황일 경우 괜찮은 선택


// ----------------------------------
// close를 호출한 곳에서 일어난 예외를 삼켜버렸을 경우 bad case
DBConn::~DBConn()
{
    try
    {
        db.close();
    }
    catch (...)
    {
        // Log : close 실패
        // 미처리
    }
}

// 대부분의 경우 예외를 삼키는 것은 좋은 발상은 아님
// 무엇이 잘못 됐는지를 알려주는 정보가 묻혀 버리기 때문
// 예외 삼키기를 선택했다는 것은 해당 예외를 무시하더라도 프로그램 신뢰성이 무너지지 않고 계속 실행 지속이 가능한 경우에 해당함


// ----------------------------------

class DBConn
{
public :
    ...
    void close()    // 사용자에게 close 권한을 부여
    {
        db.close();
        closed=true;
    }

    ~DBConn()
    {
        if (!closed)    // 사용자가 닫지 않았을 경우 해제 작업
        {
            try         // 실패시 예외 호출
            {
                db.close();
            }
            catch (...)     // 프로그램을 종료 시키거나 예외 삼켜버리면 됨
            {
                // Log : close 실패
                ...
            }
        }
    }
private:
    DBConn db;
    bool closed;
};

// close 호출의 책임을 DBConn의 소멸자에서 DBConn의 사용자로 떠넘기는 방법

// 사용자는 close가 발생한 예외를 처리할 필요가 있다면 DBConn::close함수를 try 블록내에 호출하여 예외처리 가능

// 반면 예외 처리할 필요가 없다면 DBConn의 소멸자가 예외를 삼키거나 프로그램을 종료시키도록 두면 됨.