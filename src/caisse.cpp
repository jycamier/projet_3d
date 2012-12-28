#include <GL/gl.h>
#include <GL/glu.h>
#include "caisse.h"
#include "sdlglutils.h"

Caisse::Caisse(double x, double y, double z, int height) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->height = height;

}

void Caisse::draw(GLUquadricObj * quad1) {

	int id_texture = loadTexture("textures/crate1.jpg");

	glBindTexture(GL_TEXTURE_2D, id_texture);
	glBegin (GL_QUADS);
	glColor3ub(222, 110, 18);

	glTexCoord2d(0, 1);
	glVertex3d(this->x, this->y, this->z);
	glTexCoord2d(1, 1);
	glVertex3d(this->x, this->y, this->z + this->height);
	glTexCoord2d(1, 0);
	glVertex3d(this->x, this->y + this->height, this->z + this->height);
	glTexCoord2d(0, 0);
	glVertex3d(this->x, this->y + this->height, this->z);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, id_texture);
	glBegin(GL_QUADS);
	glColor3ub(222, 110, 18);

	glTexCoord2d(0, 1);
	glVertex3d(this->x + this->height, this->y, this->z);
	glTexCoord2d(1, 1);
	glVertex3d(this->x + this->height, this->y, this->z + this->height);
	glTexCoord2d(1, 0);
	glVertex3d(this->x + this->height, this->y + this->height,
			this->z + this->height);
	glTexCoord2d(0, 0);
	glVertex3d(this->x + this->height, this->y + this->height, this->z);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, id_texture);
	glBegin(GL_QUADS);
	glColor3ub(222, 110, 18);

	glTexCoord2d(0, 1);
	glVertex3d(this->x + this->height, this->y, this->z + this->height);
	glTexCoord2d(1, 1);
	glVertex3d(this->x, this->y, this->z + this->height);
	glTexCoord2d(1, 0);
	glVertex3d(this->x, this->y + this->height, this->z + this->height);
	glTexCoord2d(0, 0);
	glVertex3d(this->x + this->height, this->y + this->height,
			this->z + this->height);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, id_texture);
	glBegin(GL_QUADS);
	glColor3ub(222, 110, 18);

	glTexCoord2d(0, 1);
	glVertex3d(this->x, this->y, this->z);
	glTexCoord2d(1, 1);
	glVertex3d(this->x + this->height, this->y, this->z);
	glTexCoord2d(1, 0);
	glVertex3d(this->x + this->height, this->y + this->height, this->z);
	glTexCoord2d(0, 0);
	glVertex3d(this->x, this->y + this->height, this->z);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, id_texture);
	glBegin(GL_QUADS);
	glColor3ub(222, 110, 18);

	glTexCoord2d(0, 1);
	glVertex3d(this->x, this->y + this->height, this->z);
	glTexCoord2d(1, 1);
	glVertex3d(this->x, this->y + this->height, this->z + this->height);
	glTexCoord2d(1, 0);
	glVertex3d(this->x + this->height, this->y + this->height,
			this->z + this->height);
	glTexCoord2d(0, 0);
	glVertex3d(this->x + this->height, this->y + this->height, this->z);

	glEnd();

	this->UpdateHitbox();

}

void Caisse::changeHeight(int height) {
	this->height = height;
}

/**
 * Mise à jour de la hitbox
 */
void Caisse::UpdateHitbox() {
	this->hitbox.x = this->x;
	this->hitbox.y = this->y;
	this->hitbox.z = this->z;

	this->hitbox.w = this->height;
	this->hitbox.h = this->height;
	this->hitbox.d = this->height;
}

bool Caisse::Collision(float x,float y,float z)
{
   if (x >= this->hitbox.x
    && x < this->hitbox.x + this->hitbox.w
    && y >= this->hitbox.y
    && y < this->hitbox.y + this->hitbox.h
    && z >= this->hitbox.z
    && z < this->hitbox.z + this->hitbox.d)
       return true;
   else
       return false;
}
