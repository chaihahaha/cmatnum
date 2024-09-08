#include "fAx248.h"

inline int fAx248(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax248.data[i][j] = bmats.A_20_17.data[i][j] + bmats.A_20_18.data[i][j] + bmats.A_20_19.data[i][j] + bmats.A_20_20.data[i][j] + bmats.A_20_21.data[i][j] + bmats.A_20_22.data[i][j] + bmats.A_20_23.data[i][j] + bmats.A_20_24.data[i][j] + bmats.A_20_27.data[i][j] + bmats.A_20_28.data[i][j] + bmats.A_20_29.data[i][j] + bmats.A_20_30.data[i][j] + bmats.A_20_31.data[i][j] + bmats.A_20_32.data[i][j];
        }
    }
    return 0;
}
