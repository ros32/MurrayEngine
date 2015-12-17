#ifndef _PHYSICS_H
#define _PHYSICS_H

struct State
{
	float x;
	float v;
};

struct Derivative
{
	float dx;
	float dv;
};

class Physics
{
public:
	Physics();
	~Physics();

	static Derivative	evaluate(const State &initial, float t, float dt, const Derivative &d);
	static float		acceleration(const State &state, float t);
	static void			integrate(State &state, float t, float dt);

private:

};

#endif // !_PHYSICS_H
