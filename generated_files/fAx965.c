#include "fAx965.h"

inline int fAx965(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax965.data[i][j] = bmats.A_10_12.data[i][j] + bmats.A_10_13.data[i][j] + bmats.A_10_14.data[i][j] + bmats.A_10_17.data[i][j] + bmats.A_10_18.data[i][j] + bmats.A_10_19.data[i][j] + bmats.A_10_20.data[i][j] + bmats.A_10_21.data[i][j] + bmats.A_10_22.data[i][j];
        }
    }
    return 0;
}
