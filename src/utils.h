#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define abs(a) ((a) < 0) ? (a) : -(a)

int clamp(int val, int low, int high);
int between(int val, int low, int high);

