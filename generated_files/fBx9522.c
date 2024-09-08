#include "fBx9522.h"

inline int fBx9522(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx9522.data[i][j] = bmats.B_25_18.data[i][j] + bmats.B_25_19.data[i][j] + bmats.B_25_20.data[i][j] + bmats.B_25_22.data[i][j] + bmats.B_25_23.data[i][j] + bmats.B_25_24.data[i][j] + bmats.B_25_26.data[i][j] + bmats.B_25_31.data[i][j] + bmats.B_25_32.data[i][j];
        }
    }
    return 0;
}
