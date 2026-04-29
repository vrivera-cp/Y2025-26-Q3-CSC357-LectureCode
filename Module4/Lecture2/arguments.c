struct point {
    int x;
    int y;
};

struct point doesnt_move(struct point p, int dx, int dy) { 
    p.x += dx; 
    p.y += dy;
    return p;
}

void does_move(struct point *p, int dx, int dy) { 
    p->x += dx;
    p->y += dy;
}

int main(void) {
    struct point p = {0, 0};

    p = doesnt_move(p, 1, 1);
    does_move(&p, 1, 1);

    return 0;
}