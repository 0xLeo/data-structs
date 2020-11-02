#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CAPACITY 4

typedef struct point_t{
	unsigned int x;
	unsigned int y;
	bool valid;
} Point;


typedef struct rect_t {
	unsigned int x;
	unsigned int y;
	unsigned int w;
	unsigned int h;
} Rect;


typedef struct qnode_t {
	struct qnode_t* ne;
	struct qnode_t* nw;
	struct qnode_t* sw;
	struct qnode_t* se;
	Rect rect;
	Point pt;
	bool isDivided;
	bool isRoot;
} Qnode;


enum {
	QUAD_NW,
	QUAD_SW,
	QUAD_SE,
	QUAD_NE,
	QUAD_OUT_OF_BOUNDS
} Quadrants;


void qtree_initNode(Qnode* qnode) {
	qnode->nw = NULL;
	qnode->sw = NULL;
	qnode->se = NULL;
	qnode->ne = NULL;
	qnode->isDivided = false;
}

static inline bool qtree_pointInRect(Point* pt, Rect* rect) {
	return ((pt->x >= rect->x) && (pt->x < rect->x + rect->w) &&
			(pt->y >= rect->y) && (pt->y < rect->y + rect->h));
}

static inline bool qtree_isChildless(Qnode* qnode) {
	return ((qnode->nw == NULL) && (qnode->sw == NULL) &&
			(qnode->se == NULL) && (qnode->ne == NULL));
}


static inline bool qtree_has4children(Qnode* qnode) {
	return ((qnode->nw != NULL) && (qnode->sw != NULL) &&
			(qnode->se != NULL) && (qnode->ne != NULL));
}



unsigned int qtree_findQuadrant(Rect* rect, Point* pt) {
	printf("(%d,%d)->(%d,%d)\n", rect->x, rect->y, rect->w, rect->h);
	unsigned int x = rect->x;
	unsigned int y = rect->y;
	unsigned int w = rect->w;
	unsigned int h = rect->h;
	Rect rectNE = {.x = x + w/2, .y = y, .w = w/2, .h =  h/2};
	Rect rectNW = {.x = x, .y = y, .w = w/2, .h =  h/2};
	Rect rectSW = {.x = x, .y = y + h/2, .w = w/2, .h =  h/2};
	Rect rectSE = {.x = x + w/2, .y = y+ h/2, .w = w/2, .h =  h/2};
	if (qtree_pointInRect(pt, &rectNE)) 
		return QUAD_NE;
	else if (qtree_pointInRect(pt, &rectNW)) 
		return QUAD_NW;
	else if (qtree_pointInRect(pt, &rectSW)) 
		return QUAD_SW;
	else if (qtree_pointInRect(pt, &rectSE)) 
		return QUAD_SE;
	else
		return QUAD_OUT_OF_BOUNDS;
}


static void qtree_setRectangle(Qnode* qnode, Rect* parentRect, Point* pt) {
	unsigned int x = qnode->rect.x;
	unsigned int y = qnode->rect.y;
	unsigned int w = qnode->rect.w;
	unsigned int h = qnode->rect.h;
	printf("splitting rect (%d,%d)->(%d,%d) for point (%d,%d)\n", x,y,w,h,pt->x, pt->y);
	if (((x <= pt->x) && (pt->x < x+w/2)) && ((y <= pt->y) && (pt->y < y+h/2))) { // NW
		qnode->nw = malloc(sizeof(Qnode));
		Rect rect = {.x = x, .y = y, .w = w/2, .h = h/2};
		qnode->nw->rect = rect;
		qnode->nw->isDivided = true;
		qnode->nw->pt = *pt;
		printf("+++ setting nw with (%d, %d)\n", qnode->nw->pt.x, qnode->nw->pt.y);
	} else if ((((x <= pt->x) && (pt->x < x+w/2))) && ((y + h/2 <= pt->y) && (pt->y < y+h))) { // SW
		qnode->sw = malloc(sizeof(Qnode));
		if (!qnode->isDivided) {
			Rect rect = {.x = x, .y = y+h/2, .w = w/2, .h = h/2};
			qnode->sw->rect = rect;
			qnode->sw->isDivided = true;
		}
		qnode->sw->pt = *pt;
		printf("here sw\n");
	} else if ((x+w/2 <= pt->x) && (pt->x < x+w) && (y + h/2 <= pt->y) && (pt->y < y+h)) { // SE
		qnode->se = malloc(sizeof(Qnode));
		if (!qnode->se->isDivided) {
			Rect rect = {.x = x+w/2, .y = y+h/2, .w = w/2, .h = h/2};
			qnode->se->rect = rect;
			qnode->se->isDivided = true;
		}
		qnode->se->pt = *pt;
		printf("here se\n");
	} else { // NE
		qnode->ne = malloc(sizeof(Qnode));
		if (!qnode->ne->isDivided) {
			printf("+++ setting NE's rect\n");
			Rect rect = {.x = x+w/2, .y = y, .w = w/2, .h = h/2};
			qnode->ne->rect = rect;
			qnode->ne->isDivided = true;
		}
		qnode->ne->pt = *pt;
		printf("here ne\n");
	}
}

void qtree_divide(Qnode* qnode) {
	// allocate children
	qnode->nw = malloc(sizeof(Qnode));
	qnode->sw = malloc(sizeof(Qnode));
	qnode->se = malloc(sizeof(Qnode));
	qnode->ne = malloc(sizeof(Qnode));
	// create rectangles
	int w = qnode->rect.w/2;
	int h = qnode->rect.h/2;
	Rect rectNw = {.x = qnode->rect.x,			.y = qnode->rect.y,			.w = w, .h = h};
	Rect rectSw = {.x = qnode->rect.x,			.y = qnode->rect.y + h/2,	.w = w, .h = h};
	Rect rectSe = {.x = qnode->rect.x + w/2,	.y = qnode->rect.y + h/2,	.w = w, .h = h};
	Rect rectNe = {.x = qnode->rect.x + w/2,	.y = qnode->rect.y, 		.w = w, .h = h};
	// initialise children
	qnode->nw->rect = rectNw;
	qnode->nw->isDivided = false;
	qnode->sw->rect = rectSw;
	qnode->sw->isDivided = false;
	qnode->se->rect = rectSe;
	qnode->se->isDivided = false;
	qnode->ne->rect = rectNe;
	qnode->ne->isDivided = false;
}


void qtree_insert(Qnode* qnode, Point* pt) {
	unsigned int quadr = qtree_findQuadrant(&qnode->rect, pt);
	printf("inserting (%d, %d) at %d\n", pt->x, pt->y, quadr);
	unsigned int newQuadr;
	Point ptPrev = qnode->pt;
	if ((quadr == QUAD_NW) && (qnode->nw == NULL)) {
		qtree_setRectangle(qnode, &qnode->rect, pt)	;
		printf("-- nonrec nw\n");
	} else if ((quadr == QUAD_NE) && (qnode->ne == NULL)) {
		printf("-- nonrec ne for (%d, %d) at node (%d, %d)\n", pt->x, pt->y, qnode->pt.x, qnode->pt.y);
		qtree_setRectangle(qnode, &qnode->rect, pt)	;
	}


	else if ((quadr == QUAD_NW) && (qnode->nw != NULL)) {
		printf("--- rect nw = %d\n", qnode->nw->rect.w);
		printf("... about to split for point (%d,%d)\n", qnode->nw->pt.x, qnode->nw->pt.y);
		qtree_setRectangle(qnode->nw, &qnode->rect, &qnode->nw->pt)	;
		unsigned int quadr = qtree_findQuadrant(&qnode->nw->rect, pt);
		printf("---rec quad = %d\n", quadr);
		qtree_insert(qnode->nw, pt);
	}
}

void qtree_init(Qnode* qnode, Rect rect) {
	qnode->nw = NULL;
	qnode->sw = NULL;
	qnode->se = NULL;
	qnode->ne = NULL;
	Point invalid = {.x = 0, .y = 0, .valid = false};
	qnode->pt = invalid;
	qnode->rect = rect;
}

//---------------------------------------------------
int main(int argc, char *argv[])
{
	Qnode* root = malloc(sizeof(Qnode));
	Rect rect = {0,0,320,320};
	qtree_init(root, rect);
	Point pt1 = {10,12};
	Point pt2 = {310,312};
	Point pt3 = {150,20};
	printf("rect = %d\n", root->rect.w);
	qtree_insert(root, &pt1);
	printf("rect = %d\n", root->rect.w);
	qtree_insert(root, &pt3);
	printf("rect = %d\n", root->rect.w);
	printf("new node = %d\n", root->nw->nw->pt.x);
	return 0;
}
