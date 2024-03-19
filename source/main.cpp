/*
 * Copyright 2024 Tedd OKANO
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include	"r01lib.h"
r01lib_start;	/* *** place this word before making instance of r01lib classes *** */

SPI			spi( 1000000, 0 );	//	SCK frequency, mode

int main(void)
{
	uint8_t	write_data[ 8 ]	= { 0x00, 0x01, 0x02, 0x03, 0xFF, 0xFE, 0xFD, 0xFC };
	uint8_t	read_data[ 8  ]	= { 0x00 };

	PRINTF( "Watch the SPI signal on D10:CS, D11:MOSI, D12:MISO and D13:SCK\r\n" );
	PRINTF( "Loop back data will be shown when D11:MOSI and D12:MISO are shorted\r\n" );

	while ( true )
	{
		spi.write( write_data, read_data, sizeof( write_data ) );

		for ( int i = 0; i < sizeof( read_data ); i++ )
			PRINTF( " 0x%02X", read_data[ i ] );

		PRINTF( "\r\n" );
		wait( 0.2 );
	}
}

