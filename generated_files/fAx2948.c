#include "fAx2948.h"

inline int fAx2948(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2948.data[i][j] = bmats.A_31_17.data[i][j] + bmats.A_31_18.data[i][j] + bmats.A_31_19.data[i][j] + bmats.A_31_20.data[i][j] + bmats.A_31_21.data[i][j] + bmats.A_31_22.data[i][j] + bmats.A_31_23.data[i][j] + bmats.A_31_24.data[i][j] + bmats.A_31_27.data[i][j] + bmats.A_31_28.data[i][j] + bmats.A_31_29.data[i][j] + bmats.A_31_30.data[i][j] + bmats.A_31_31.data[i][j] + bmats.A_31_32.data[i][j];
        }
    }
    return 0;
}
