#include "fAx39.h"

inline int fAx39(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax39.data[i][j] = bmats.A_21_17.data[i][j] + bmats.A_21_18.data[i][j] + bmats.A_21_19.data[i][j] + bmats.A_21_20.data[i][j] + bmats.A_21_21.data[i][j] + bmats.A_21_22.data[i][j] + bmats.A_21_23.data[i][j] + bmats.A_21_24.data[i][j] + bmats.A_21_25.data[i][j] + bmats.A_21_26.data[i][j] + bmats.A_21_29.data[i][j] + bmats.A_21_30.data[i][j] + bmats.A_21_31.data[i][j] + bmats.A_21_32.data[i][j];
        }
    }
    return 0;
}
