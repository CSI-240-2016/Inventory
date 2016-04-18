class Date
{
	private:
		int mMonth, mDay, mYear;

	public:
		//Constructors
		Date();
		Date(int day, int month, int year);
		~Date();

		//Accessors
		int getDay();
		int getMonth();
		int getYear();

		//Mutators
		void setDay(int day);
		void setMonth(int month);
		void setYear(int year);

		//Overloaded Operators
		friend bool operator == (Date& dateOne,Date& dateTwo);
		friend bool operator >= (Date& dateOne, Date& dateTwo);
		friend bool operator <= (Date& dateOne, Date& dateTwo);
		friend bool operator != (Date& dateOne, Date& dateTwo);
};