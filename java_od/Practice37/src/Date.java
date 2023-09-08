// 20220803 컴퓨터학과 정여진
public class Date {
	private int year;
	private int month;
	private int day;
	
	public int getYear() {
		return year;
	}
	public void setYear(int y) {
		year = y;
	}
	public int getMonth() {
		return month;
	}
	public void setMonth(int m) {
		month = m;
	}
	public int getDay() {
		return day;
	}
	public void setDay(int d) {
		day = d;
	}
	
	public Date() {
		year = 1990;
		month = 1;
		day = 1;
	}
	public Date(int y) {
		year = y;
	}
	public Date(int y, int m) {
		year = y;
		month = m;
	}
	public Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	
	public String toString() {
		String rslt = year + "년 " + month + "일 " + day + "일";
		
		return rslt;
	}
	protected boolean isReap(int year) {
		
		if(year % 4 == 0) {
			return true;
		}
		else if(year % 100 == 0) {
			return false;
		}
		return false;
	} // 소속변수 year에 저장된 값을 가지고 윤년 여부를 판단한다.
	public String testReapYears() {
		
		String str = " ";
		
		if(isReap(year)) {
			str = year + "년은 윤년입니다.";
		}
		else if(!isReap(year)) {
			str = year + "년은 윤년이 아닙니다.";
		}
		return str;
		
	} 
	public String printWestern() {
		String[] s = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "Nobember", "December"};
		
		for(int i = 0; i < 11; i++) {
			if(i + 1 == month) {
				return s[i] + " " + day + "," + year;
			}	
		}
		return null;
	}
	
	public static int compareDate(Date x, Date y) {
		if(x.getYear() > y.getYear()) {
			return 1;
		}
		if(x.getYear() < y.getYear()) {
			return -1;
		}
		if(x.getMonth() > y.getMonth()) {
			return 1;
		}
		if(x.getMonth() < y.getMonth()) {
			return -1;
		}
		if(x.getDay() > y.getDay()){
			return 1;
		}
		if(x.getDay() < y.getDay()) {
			return -1;
		}
		else
			return 0;
	}
}