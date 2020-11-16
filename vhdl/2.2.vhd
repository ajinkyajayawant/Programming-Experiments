library ieee;
use ieee.std_logic_1164.all;

entity mux4  is
  
  port (
    i0               : in  std_logic;
    i1, i2, i3, a, b : in  std_logic;
    q                : out std_logic);

end mux4 ;

architecture mux4 of mux4 is

begin  -- mux4

  with sel select
    q <= 
    i0 when after,
    i1 when <[choices]>

end mux4;
