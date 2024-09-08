#include "fAx6804.h"

inline int fAx6804(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax6804.data[i][j] = 2*bmats.A_28_19.data[i][j] + 2*bmats.A_28_20.data[i][j] + 2*bmats.A_28_21.data[i][j] + 2*bmats.A_28_22.data[i][j] + 2*bmats.A_28_23.data[i][j] + 2*bmats.A_28_24.data[i][j] + 2*bmats.A_28_25.data[i][j] + 2*bmats.A_28_26.data[i][j] + 2*bmats.A_28_27.data[i][j] - 15*bmats.A_28_28.data[i][j] + 2*bmats.A_28_29.data[i][j] + 2*bmats.A_28_30.data[i][j] + 2*bmats.A_28_31.data[i][j] + 2*bmats.A_28_32.data[i][j];
        }
    }
    return 0;
}
