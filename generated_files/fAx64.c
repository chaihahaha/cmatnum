#include "fAx64.h"

inline int fAx64(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax64.data[i][j] = bmats.A_27_19.data[i][j] + bmats.A_27_20.data[i][j] + bmats.A_27_21.data[i][j] + bmats.A_27_22.data[i][j] + bmats.A_27_23.data[i][j] + bmats.A_27_24.data[i][j] + bmats.A_27_25.data[i][j] + bmats.A_27_26.data[i][j] + bmats.A_27_27.data[i][j] + bmats.A_27_28.data[i][j] + bmats.A_27_29.data[i][j] + bmats.A_27_30.data[i][j] + bmats.A_27_31.data[i][j] + bmats.A_27_32.data[i][j];
        }
    }
    return 0;
}
