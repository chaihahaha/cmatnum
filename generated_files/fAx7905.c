#include "fAx7905.h"

inline int fAx7905(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax7905.data[i][j] = -bmats.A_31_19.data[i][j] - bmats.A_31_20.data[i][j] - bmats.A_31_21.data[i][j] - bmats.A_31_22.data[i][j] - bmats.A_31_23.data[i][j] - bmats.A_31_24.data[i][j] - bmats.A_31_25.data[i][j] - bmats.A_31_26.data[i][j] - bmats.A_31_27.data[i][j] - bmats.A_31_28.data[i][j] - bmats.A_31_29.data[i][j];
        }
    }
    return 0;
}