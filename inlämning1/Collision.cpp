#include "Collision.h"


Collision::Collision() {
	
}

Collision::Collision(int collX, int collY, int collWidth, int collHeight){
		
	CollRectangle.x = collX;
	CollRectangle.y = collY;
	CollRectangle.h = collHeight;
	CollRectangle.w = collWidth;
	
}


void Collision::setCollisionArea(int x, int y, int width, int height) {
	
}

void Collision::setX(int x) {
	CollRectangle.x = x ;

}
void Collision::setY(int y) {

	CollRectangle.y = y ;
}

SDL_Rect Collision::getCollision() {

	return CollRectangle;
}