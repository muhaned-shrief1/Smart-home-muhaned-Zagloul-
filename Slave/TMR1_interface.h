
#ifndef TMR1_INTERFACE_H_
#define TMR1_INTERFACE_H_


void TMR1_init                 (void);
void TMR1_start                (void);
void TMR1_setCompareMatchValueA(uint16 value);
void TMR1_stop(void);

#endif /* TMR1_INTERFACE_H_ */
