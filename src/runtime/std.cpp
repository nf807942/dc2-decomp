/* std
 *
 * Unité découpée par `make carve` : 40 fonctions, 9308 octets, de
 * 0x001000D0 à 0x00102630. Chacune garde les instructions du disque
 * jusqu'à ce qu'elle soit écrite en C++, et l'ordre est celui des adresses,
 * que l'éditeur de liens attend.
 */

#include "common.h"

extern "C" s32 dpcmp(...);
extern "C" s32 _dpfne(void) {
    return dpcmp() != 0;
}
extern "C" s32 dpcmp(...);
extern "C" s32 _dpflt(void) {
    return dpcmp() < 0;
}
extern "C" s32 dpcmp(...);
extern "C" s32 _dpfle(void) {
    return dpcmp() <= 0;
}
extern "C" s32 _dpfgt(void) {
    return dpcmp() > 0;
}
extern "C" s32 _dpfge(void) {
    return dpcmp() >= 0;
}
INCLUDE_ASM("nonmatchings/runtime/std", mwInit);
INCLUDE_ASM("nonmatchings/runtime/std", __construct_array);
INCLUDE_ASM("nonmatchings/runtime/std", __construct_new_array);
INCLUDE_ASM("nonmatchings/runtime/std", __dl__FPv);
INCLUDE_ASM("nonmatchings/runtime/std", __dt__Q23std9exceptionFv);
INCLUDE_ASM("nonmatchings/runtime/std", what__Q23std9exceptionCFv);
INCLUDE_ASM("nonmatchings/runtime/std", default_new_handler__3stdFv);
INCLUDE_ASM("nonmatchings/runtime/std", __dt__Q23std9bad_allocFv);
INCLUDE_ASM("nonmatchings/runtime/std", what__Q23std9bad_allocCFv);
INCLUDE_ASM("nonmatchings/runtime/std", __nw__FUi);
INCLUDE_ASM("nonmatchings/runtime/std", __throw_catch_compare);
INCLUDE_ASM("nonmatchings/runtime/std", unexpected__3stdFv);
INCLUDE_ASM("nonmatchings/runtime/std", terminate__3stdFv);
INCLUDE_ASM("nonmatchings/runtime/std", duhandler__3stdFv);
INCLUDE_ASM("nonmatchings/runtime/std", dthandler__3stdFv);
INCLUDE_ASM("nonmatchings/runtime/std", __register_global_object);
INCLUDE_ASM("nonmatchings/runtime/std", __initialize_cpp_rts);
INCLUDE_ASM("nonmatchings/runtime/std", __DecodeUnsignedNumber__FPcPUi);
INCLUDE_ASM("nonmatchings/runtime/std", __DecodeSignedNumber__FPcPi);
INCLUDE_ASM("nonmatchings/runtime/std", __end__catch);
INCLUDE_ASM("nonmatchings/runtime/std", __ThrowHandler__FP12ThrowContext);
INCLUDE_ASM("nonmatchings/runtime/std", FindExceptionHandler__FP12ThrowContextP13ExceptionInfoPl);
INCLUDE_ASM("nonmatchings/runtime/std", __unexpected);
INCLUDE_ASM("nonmatchings/runtime/std", __dt__Q23std13bad_exceptionFv);
INCLUDE_ASM("nonmatchings/runtime/std", FindMostRecentException__FP12ThrowContextP13ExceptionInfo);
INCLUDE_ASM("nonmatchings/runtime/std", UnwindStack__FP12ThrowContextP13ExceptionInfoPc);
INCLUDE_ASM("nonmatchings/runtime/std", NextAction__FP14ActionIterator);
INCLUDE_ASM("nonmatchings/runtime/std", FindExceptionRecord__FPcP13ExceptionInfo);
INCLUDE_ASM("nonmatchings/runtime/std", what__Q23std13bad_exceptionCFv);
INCLUDE_ASM("nonmatchings/runtime/std", __TransferControl__FP12ThrowContextP13ExceptionInfoPc);
INCLUDE_ASM("nonmatchings/runtime/std", __throw);
extern "C" s32 __DecodeUnsignedNumber__FPcPUi(...);
extern "C" void __SkipUnwindInfo__FPc(s8 *arg0) {
    u32 sp2C;
    s32 temp_s0;
    s8 *temp_a0;

    temp_s0 = *arg0 & 0x40;
    temp_a0 = (s8 *) (__DecodeUnsignedNumber__FPcPUi(__DecodeUnsignedNumber__FPcPUi(arg0 + 1, &sp2C), &sp2C));
    if (temp_s0 != 0) {
        __DecodeUnsignedNumber__FPcPUi(temp_a0, &sp2C);
    }
}
INCLUDE_ASM("nonmatchings/runtime/std", __FindExceptionTable__FP13ExceptionInfoPc);
INCLUDE_ASM("nonmatchings/runtime/std", __SetupFrameInfo__FP12ThrowContextP13ExceptionInfo);
INCLUDE_ASM("nonmatchings/runtime/std", __PopStackFrame__FP12ThrowContextP13ExceptionInfo);
