#ifndef TIME_H_
#define TIME_H_

class Time {
private:
	long h, m, s;
	void correct();

public:
	Time(long h = 0, long m = 0, long s = 0);

	long hour() const {
		return h;
	}

	long minute() const {
		return m;
	}

	long second() const {
		return s;
	}

	void add(const Time &other);
	void add_hours(long hours);
	void add_minutes(long minutes);
	void add_seconds(long seconds);
	long justseconds() const;
	long diff(const Time &other);
	std::string ausgabe() const;
};

#endif
