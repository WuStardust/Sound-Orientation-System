#include <xc.h>
#include <stdint.h>
#include <plib.h>

#include "cmp_extra.h"
#include "led.h"

void cmp_init()
{
    CVREFOpen(CVREF_ENABLE, CVREF_OUTPUT_DISABLE, CVREF_RANGE_HIGH, CVREF_SOURCE_AVDD, CVREF_STEP_13);

    CMP1Open(CMP_ENABLE | CMP_OUTPUT_NONINVERT | CMP_OUTPUT_DISABLE | CMP_RUN_IN_IDLE | CMP_EVENT_LOW_TO_HIGH | CMP_POS_INPUT_CVREF | CMP1_NEG_INPUT_C1IN_POS);
    CMP1ConfigInt(mCMP1ClearIntFlag() | mCMP1SetIntPriority(7) | mCMP1SetIntSubPriority(3) | CMP_INT_ENABLE);

    CMP2Open(CMP_ENABLE | CMP_OUTPUT_NONINVERT | CMP_OUTPUT_DISABLE | CMP_RUN_IN_IDLE | CMP_EVENT_LOW_TO_HIGH | CMP_POS_INPUT_CVREF | CMP2_NEG_INPUT_C2IN_POS);
    CMP2ConfigInt(mCMP2ClearIntFlag() | mCMP2SetIntPriority(7) | mCMP2SetIntSubPriority(3) | CMP_INT_ENABLE);

    CMP3Open(CMP_ENABLE | CMP_OUTPUT_NONINVERT | CMP_OUTPUT_DISABLE | CMP_RUN_IN_IDLE | CMP_EVENT_LOW_TO_HIGH | CMP_POS_INPUT_CVREF | CMP3_NEG_INPUT_IVREF);
    CMP3ConfigInt(mCMP3ClearIntFlag() | mCMP3SetIntPriority(7) | mCMP3SetIntSubPriority(3) | CMP_INT_ENABLE);
}

void __ISR(_COMPARATOR_3_VECTOR, ipl7) _MK1RecievedSound(void)
{
    led_set(0, ON);
    led_set(1, ON);
    int i;
    for (i = 0; i < 5000000; i ++);
    led_set(0, OFF);
    led_set(1, OFF);
    mCMP3ClearIntFlag();
    mCMP2ClearIntFlag();
    mCMP1ClearIntFlag();
}

void __ISR(_COMPARATOR_1_VECTOR, ipl7) _MK2RecievedSound(void)
{
    led_set(3, ON);
    int i;
    for (i = 0; i < 5000000; i ++);
    led_set(3, OFF);
    mCMP2ClearIntFlag();
    mCMP1ClearIntFlag();
    mCMP3ClearIntFlag();
}

void __ISR(_COMPARATOR_2_VECTOR, ipl7) _MK3RecievedSound(void)
{
    led_set(6, ON);
    int i;
    for (i = 0; i < 5000000; i ++);
    led_set(6, OFF);
    mCMP1ClearIntFlag();
    mCMP2ClearIntFlag();
    mCMP3ClearIntFlag();
}