#include "fAx3740.h"

inline int fAx3740(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3740.data[i][j] = -bmats.A_7_17.data[i][j] - bmats.A_7_18.data[i][j] - bmats.A_7_19.data[i][j] - bmats.A_7_20.data[i][j] - bmats.A_7_21.data[i][j] - bmats.A_7_22.data[i][j] - bmats.A_7_23.data[i][j] - bmats.A_7_24.data[i][j] - bmats.A_7_25.data[i][j] - bmats.A_7_26.data[i][j] - bmats.A_7_27.data[i][j] - bmats.A_7_28.data[i][j] - bmats.A_7_31.data[i][j] - bmats.A_7_32.data[i][j] + bmats.Ax3692.data[i][j];
        }
    }
    return 0;
}