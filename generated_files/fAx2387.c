#include "fAx2387.h"

inline int fAx2387(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2387.data[i][j] = bmats.A_12_17.data[i][j] + bmats.A_12_18.data[i][j] + bmats.A_12_19.data[i][j] + bmats.A_12_20.data[i][j] + bmats.A_12_21.data[i][j] + bmats.A_12_22.data[i][j] + bmats.A_12_23.data[i][j] + bmats.A_12_24.data[i][j] + bmats.A_12_27.data[i][j] + bmats.A_12_28.data[i][j] + bmats.A_12_29.data[i][j] + bmats.A_12_30.data[i][j] + bmats.A_12_31.data[i][j] + bmats.A_12_32.data[i][j];
        }
    }
    return 0;
}