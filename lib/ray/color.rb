module Ray
  class Color
    class << self
      def red;     new(255, 0, 0);     end
      def green;   new(0, 255, 0);     end
      def blue;    new(0, 0, 255);     end
      def black;   new(0, 0,0);        end
      def white;   new(255, 255, 255); end
      def none;    new(0, 0, 0, 0);    end
      def gray;    new(128, 128, 128); end
      def cyan;    new(0, 255, 255);   end
      def yellow;  new(255, 255, 0);   end
      def fuschia; new(255, 0, 255);   end
    end

    def inspect
      "RGBA(#{r}, #{g}, #{b}, #{a})"
    end

    def ==(obj)
      return false unless obj.is_a? Color
      r == obj.r && g == obj.g && b == obj.b && a == obj.a
    end

    def to_color
      self
    end

    alias :red :r
    alias :green :g
    alias :blue :b
    alias :alpha :a

    alias :red= :r=
    alias :green= :g=
    alias :blue= :b=
    alias :alpha= :a=
  end
end

class Array
  # Converts an Array to a color
  def to_color
    Ray::Color.new(*self)
  end
end
