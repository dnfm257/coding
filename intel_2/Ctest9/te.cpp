#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

class Car
{
	std::string car_num; // 차량번호
	time_t park_time; // 주차시간
	time_t exit_time; // 출차시간
	std::string location; // 배차 위치
	bool unable_car; // 장애인차량 유무
public:
	std::string getCarNum() { return car_num; }
	time_t getParkTime() { return park_time; }
	time_t getExitTime() { return exit_time; }
	std::string getLocation() { return location; }
	bool getUnableCar() { return unable_car; }

	void setCarNum(std::string car_num) { this->car_num = car_num; }
	void setParkTime(time_t park_time) { this->park_time = park_time; }
	void setExitTime(time_t exit_time) { this->exit_time = exit_time; }
	void setLocation(std::string location) { this->location = location; }
	void setUnableCar(bool unable_car) { this->unable_car = unable_car; }

	Car();
    Car(const Car& obj);
	Car(std::string c, int date, int hour, int min, std::string l, bool u);
	Car(std::string c, time_t p, time_t e, std::string l, bool u);
	~Car();

	int calc_pay();
};

Car::Car() {
	car_num = "0000";
	park_time = 0;
	exit_time = time(NULL);
	location = "";
	unable_car = false;
}
Car::Car(const Car& obj){ // 복사생성자
    car_num = obj.car_num;
    park_time = obj.park_time;
    exit_time = obj.exit_time;
    location = obj.location;
    unable_car = obj.unable_car;
}
Car::Car(std::string c, int date, int hour, int min, std::string l, bool u) {
	struct tm user_park_time; // 주차시간 구조체
	user_park_time.tm_year = 123; // 2023 - 1900
	user_park_time.tm_mon = 8; // 0부터 시작, 8 = 9월
	user_park_time.tm_mday = date;
	user_park_time.tm_hour = hour; // 24시 기준
	user_park_time.tm_min = min;
	user_park_time.tm_sec = 59;
	user_park_time.tm_isdst = 0; // 썸머타임 false

	car_num = c;
	park_time = mktime(&user_park_time);
	exit_time = time(NULL);
	location = l;
	unable_car = u;
}
Car::Car(std::string c, time_t p, time_t e, std::string l, bool u) {
	car_num = c;
	park_time = p;
	exit_time = e;
	location = l;
	unable_car = u;
}
int Car::calc_pay() {
	int times = difftime(exit_time, park_time);

	int h_1 = times / (60 * 60);
	times -= h_1 * (60 * 60);

	int m_30 = 0;
	if (times > 1800) {
		m_30 = times / (60 * 30);
		times -= m_30 * (60 * 30);
	}

	int m_10 = 0;
	if ((times % (60 * 10)) != 0) {
		m_10 = times / (60 * 10);
		m_10 += 1;
	}
	else
		m_10 = times / (60 * 10);

	int res = h_1 * 2000 + m_30 * 1000 + m_10 * 400;

	return res;
}

Car::~Car() {}

inline void print_carinfo(Car obj){
    cout << obj.getCarNum() << "  " << obj.getParkTime() << "  " << obj.getExitTime()
    << "  " << obj.getLocation() << "  장애인 차:" << boolalpha << obj.getUnableCar() << endl;
}

// 복사 생성자 사용
void copy_func(){
    Car a("2104", (time_t)21, (time_t)42, "B3", false);
    Car b(a);

    print_carinfo(a);
    print_carinfo(b);
}
void car_find(){
    Car list[] = {Car("2104", (time_t)21, (time_t)42, "B3", false),
                    Car("7325", (time_t)10, (time_t)54, "A4", true),
                    Car("1234", (time_t)35, (time_t)98, "C1", false)};

    cout << "찾으려고 하는 차량의 번호를 적어주세요 >>";
    string str;
    cin >> str;

    int siz = (int)(sizeof(list) / sizeof(list[0]));
    for(int i = 0; i < siz; i++){
        if(!str.compare(list[i].getCarNum())){
            print_carinfo(list[i]);
        }
    }
}

int main(){
    copy_func();
    car_find();

    

    
}

// 얕은 복사
// 객체에 참조 타입의 멤버가 있다면 참조값만 복사

// 깊은 복사
// 참조된 객체 자체가 복사


// 인라인 함수
// 장점: 함수 오버헤드를 제거해 속도를 높임
// 단점: 인라인 함수가 길거나 여러번 호출할 경우 컴파일 코드가 커지는 현상이 생길 수 있음


// public = 어디서든 접근 허용
// protected = 상속 관계일 때 유도클래스에서의 접근 허용 
// private = 클래스 내에서만 접근 허용
// 멤버변수 =  클래스 내에 선언되는 변수, 메서드 외부에 선언되며 해당 클래스의 모든함수에서 접근이 가능
// 지역변수 = 메서드 내부에서 생성되어 stack에 저장되며, 선언된 함수 내부에서 사용되고 함수가 종료되면 소멸
// 전역변수 = 프로그램이 시작 될 때 생성되어 Data 영역에 저장되며, 프로그램 전체에서 사용 가능하고 프로그램이 종료되면 소멸