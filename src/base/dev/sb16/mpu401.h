/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#ifndef MPU401_H
#define MPU401_H

#include <stdint.h>

struct mpu401_s;

struct mpu401_ops {
    void (*activate_irq)(void);
    void (*deactivate_irq)(void);
    void (*run_irq)(void);
};

int mpu401_is_uart(struct mpu401_s *mpu);
void mpu401_write_midi(struct mpu401_s *mpu, uint8_t val);
void mpu401_process(struct mpu401_s *mpu);

struct mpu401_s *mpu401_init(ioport_t base, enum SynthType stype,
	struct mpu401_ops *ops);
void mpu401_reset(struct mpu401_s *mpu);
void mpu401_done(struct mpu401_s *mpu);

#endif
