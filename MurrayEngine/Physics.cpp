#define _CRTDBG_MAP_ALLOC
#include "Physics.h"

float Physics::acceleration(const State &state, float t)
{
	const float k = 10;
	const float b = 1;
	return -k * state.x - b*state.v;
}

Derivative	Physics::evaluate(const State &initial, float t, float dt, const Derivative &d)
{
	State state;
	state.x = initial.x + d.dx*dt;
	state.v = initial.v + d.dv*dt;

	Derivative output;
	output.dx = state.v;
	output.dv = acceleration(state, t + dt);
	return output;
}

void Physics::integrate(State &state,
	float t,
	float dt)
{
	Derivative a, b, c, d;

	a = evaluate(state, t, 0.0f, Derivative());
	b = evaluate(state, t, dt*0.5f, a);
	c = evaluate(state, t, dt*0.5f, b);
	d = evaluate(state, t, dt, c);

	float dxdt = 1.0f / 6.0f *
		(a.dx + 2.0f*(b.dx + c.dx) + d.dx);

	float dvdt = 1.0f / 6.0f *
		(a.dv + 2.0f*(b.dv + c.dv) + d.dv);

	state.x = state.x + dxdt * dt;
	state.v = state.v + dvdt * dt;
}