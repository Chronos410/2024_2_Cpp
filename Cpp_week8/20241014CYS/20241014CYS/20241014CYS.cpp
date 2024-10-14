#include <iostream>
#include "Human.hpp"
#include "Gun.hpp"

int main()
{
	Human h1(1,1,1,5,true);
	Gun g1;

	h1.Move();
	h1.Die();
	h1.PlusMaxHp(6);
	h1.MinusMaxHp(3);
	h1.GetDamage(3);
	 
	g1.Fire();
	g1.Aim(1);
	g1.CheckBullet();
	g1.Reload();
	g1.GunBroke(); 
}