#ifndef bookscanner_h
#define bookscanner_h
#include <Arduino.h>
#include <Stepper.h>

typedef char Error;
#define ERROR_OK 0

typedef struct {
    Error error;
    char payload_len;
    char payload[16]; 
} Response;

class Bookscanner {
  public:
    Bookscanner();
    ~Bookscanner();
    
    /// Raises box to maximum position
    Response raise_box();

    /// Lowers box to minimum position and recalibrate 0 position.
    Response lower_box();

    /// Set box lighting
    /// @param state: new lighting state,
    Response set_lights(bool state);

    /// Run a Complete Page flip cycle autonomously
    /// @param page_size: Size of the page we are flipping in mm
    Response flip_page(uint8_t page_size);
  private:
    Stepper motor;

    // on an AVR these are 16Bit Values
    int head_pos; // Position of the head in steps from the book
    
    bool move_to(int pos);
    void set_drivers(bool state);
};

#endif
