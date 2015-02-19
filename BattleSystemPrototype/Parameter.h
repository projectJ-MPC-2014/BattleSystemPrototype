#pragma once

#include<cassert>


template<int min, int max>
class Parameter
{
private:
	int param_m;
public:
	Parameter(int param);
	Parameter(const Parameter<min, max>& param);
	virtual ~Parameter();
protected:
public:
	void set(int param);
	void set(const Parameter<min, max>& param);
	Parameter<min, max>get();
};


template<int min, int max>
inline Parameter<min, max>::Parameter(int param)
{
	set(param);
}

template<int min, int max>
inline Parameter<min, max>::Parameter(const Parameter<min, max>& param)
{
	set(param);
}

template<int min, int max>
inline Parameter<min, max>::~Parameter(){}


template<int min, int max>
inline void Parameter<min, max>::set(int param)
{
	assert(min <= param && param <= max);

	param_m = param;
}

template<int min, int max>
inline void Parameter<min, max>::set(const Parameter<min, max>& param)
{
	set(param);
}

template<int min, int max>
inline Parameter<min,max> Parameter<min, max>::get()
{
	return Parameter(param_m);
}