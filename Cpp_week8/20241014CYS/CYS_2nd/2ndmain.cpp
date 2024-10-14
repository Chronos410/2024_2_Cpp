#include "2ndHuman.hpp"
int main() 
{
	Human hs[100];
	Gun gs[100];

	for (int i = 0; i < 100; i++) 
	{
		hs[i] = Human(i, 1, 1, 5, true);
		gs[i] = Gun(i, 30, 30, 1, false);
		hs[i].ChangeGun(&gs[i]);
		hs[i].GunFire();
		hs[i].GunReload();
	}
}