#include "fAx1094.h"

inline int fAx1094(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax1094.data[i][j] = bmats.A_23_17.data[i][j] + bmats.A_23_18.data[i][j] + bmats.A_23_19.data[i][j] + bmats.A_23_20.data[i][j] + bmats.A_23_21.data[i][j] + bmats.A_23_22.data[i][j] + bmats.A_23_23.data[i][j] + bmats.A_23_24.data[i][j] + bmats.A_23_25.data[i][j] + bmats.A_23_26.data[i][j] + bmats.A_23_27.data[i][j] + bmats.A_23_28.data[i][j] + bmats.A_23_31.data[i][j] + bmats.A_23_32.data[i][j];
        }
    }
    return 0;
}