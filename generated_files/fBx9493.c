#include "fBx9493.h"

inline int fBx9493(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx9493.data[i][j] = bmats.B_30_18.data[i][j] + bmats.B_30_19.data[i][j] + bmats.B_30_20.data[i][j] + bmats.B_30_21.data[i][j] + bmats.B_30_31.data[i][j] + bmats.Bx2480.data[i][j];
        }
    }
    return 0;
}
