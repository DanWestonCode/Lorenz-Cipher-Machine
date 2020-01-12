#include "stdafx.h"
#include "lorenzWheel.h"

lorenzWheel::lorenzWheel()
{
}

lorenzWheel::lorenzWheel(std::string pins)
{
	m_pins = pins;
	m_pos = 0;
}

lorenzWheel::~lorenzWheel()
{
}

/**
 * Rotate/advance the wheel forward. Will wrap back to 0 when spun all the way
 */
void lorenzWheel::rotate()
{
	m_pos = m_pos + 1 >= m_pins.length() ? 0 : m_pos + 1;
}

/**
 * Reset the wheel back to its starting position
 */
void lorenzWheel::reset()
{
	m_pos = 0;
}

/**
 * Get the current pin value at the wheels position
 */
char lorenzWheel::current()
{
	return m_pins[m_pos];
}
