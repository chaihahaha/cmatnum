#include "fAx4417.h"

inline int fAx4417(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax4417.data[i][j] = -bmats.A_4_17.data[i][j] - bmats.A_4_18.data[i][j] - bmats.A_4_19.data[i][j] - bmats.A_4_20.data[i][j] - bmats.A_4_21.data[i][j] - bmats.A_4_23.data[i][j] - bmats.A_4_24.data[i][j] - bmats.A_4_25.data[i][j] - bmats.A_4_26.data[i][j] - bmats.A_4_28.data[i][j] - bmats.A_4_29.data[i][j] - bmats.A_4_30.data[i][j] - bmats.A_4_31.data[i][j] - bmats.A_4_32.data[i][j] + bmats.Ax4311.data[i][j];
        }
    }
    return 0;
}
