#include "fAx530.h"

inline int fAx530(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax530.data[i][j] = -bmats.A_14_17.data[i][j] - bmats.A_14_18.data[i][j] - bmats.A_14_19.data[i][j] - bmats.A_14_20.data[i][j] - bmats.A_14_21.data[i][j] - bmats.A_14_22.data[i][j] - bmats.A_14_23.data[i][j] - bmats.A_14_24.data[i][j] - bmats.A_14_25.data[i][j] - bmats.A_14_26.data[i][j] - bmats.A_14_27.data[i][j] - bmats.A_14_28.data[i][j] - bmats.A_14_30.data[i][j] - bmats.A_14_31.data[i][j] + bmats.Ax529.data[i][j];
        }
    }
    return 0;
}