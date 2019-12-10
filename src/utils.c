int clamp(int val, int low, int high) {
    if (val < low) return low;
    else if (val > high) return high;
    else return val;
}

int between(int val, int low, int high) {
    return clamp(val, low, high) == val;
}