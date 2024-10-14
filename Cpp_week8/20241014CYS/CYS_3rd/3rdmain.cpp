#include "3rdGun_bullet.hpp"
#include "3rdGun_Laser.hpp"
#include "3rdHuman.hpp"

int main() 
{
	Human h1{ 1,1,1,1,true };
	GunBullet gb{ 5,5,5,5,false };
	GunLaser gl{ 9,9,9,9,false };
	
	h1.ChangeGunBullet(&gb);
	h1.GunFire();

	h1.ChangeGunLaser(&gl);
	h1.GunFire();
}