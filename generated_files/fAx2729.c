#include "fAx2729.h"

inline int fAx2729(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2729.data[i][j] = bmats.A_11_17.data[i][j] + bmats.A_11_18.data[i][j] + bmats.A_11_19.data[i][j] + bmats.A_11_20.data[i][j] + bmats.A_11_21.data[i][j] + bmats.A_11_22.data[i][j] + bmats.A_11_25.data[i][j] + bmats.A_11_26.data[i][j] + bmats.A_11_27.data[i][j] + bmats.A_11_28.data[i][j] + bmats.A_11_29.data[i][j] + bmats.A_11_30.data[i][j] + bmats.A_11_31.data[i][j] + bmats.A_11_32.data[i][j];
        }
    }
    return 0;
}