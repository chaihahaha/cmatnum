#include "fAx4218.h"

inline int fAx4218(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4218.data[i][j] = -bmats.A_5_17.data[i][j] - bmats.A_5_18.data[i][j] - bmats.A_5_19.data[i][j] - bmats.A_5_20.data[i][j] - bmats.A_5_23.data[i][j] - bmats.A_5_24.data[i][j] - bmats.A_5_25.data[i][j] - bmats.A_5_26.data[i][j] - bmats.A_5_27.data[i][j] - bmats.A_5_28.data[i][j] - bmats.A_5_29.data[i][j] - bmats.A_5_30.data[i][j] - bmats.A_5_31.data[i][j] - bmats.A_5_32.data[i][j] + bmats.Ax4141.data[i][j];
        }
    }
    return 0;
}
