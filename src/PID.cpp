#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  p_error = 0;
  i_error = 0;
  d_error = 0;

}

void PID::UpdateError(double cte) {
  
  i_error += cte;
	d_error = cte - p_error;
	p_error = cte;
}

double PID::TotalError(double speed) {
	double sas= -((Kp-speed*0.004) * p_error + Ki * i_error + (Kd+speed*0.005) * d_error);
	if (sas > 1){
		sas = 1;
	}
	if (sas <-1){
		sas = -1;
  }
	return sas;
}

