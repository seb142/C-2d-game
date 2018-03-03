#pragma once
class Main {

	
public:
	Main();
	~Main();
	bool running() { return run; };
	void setRunFalse() { run = false; };
	void setRunTrue() { run = true; };


private:
	bool run;

};