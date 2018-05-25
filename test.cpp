#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

class Window
{
  public:
  
   Window(const std::string & t, int w, int h) : title(t), width(w), height(h)
   {
   
    closed = !init();
   }

   ~Window()
   {
     SDL_DestroyRenderer(renderer);
     SDL_DestroyWindow(window);
     SDL_Quit();
   }

   bool init()
   {
     if (SDL_Init(SDL_INIT_VIDEO) != 0)
     {
        std::cerr << "Failed to initialize SDL!\n";
        return false;
     }

      else
     {
       window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);

      if (window == nullptr)
       {
        std::cerr << "Failed to create window!\n";
        return false;
       }

      renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr)
        {
          std::cerr << "Failed to create renderer" << '\n';
          return false;
        }
        
       if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
       {
          std::cerr << "Failed to initialize SDL Image" << '\n';
          return false;
       }
       return true;
      }
    }
  void events(SDL_Event & event)
  {
     switch(event.type)
     {
       case SDL_QUIT:
        closed = true;
        break;
        case SDL_MOUSEMOTION:
        
          if ((event.motion.x >= 720 and event.motion.x <= 780) and (event.motion.y >= 20 and event.motion.y <= 110))
            std::cout << event.motion.x << ", Letra A, " << event.motion.y << '\n';
          
          if ((event.motion.x >= 795 and event.motion.x <= 850) and (event.motion.y >= 20 and event.motion.y <= 110))
            std::cout << event.motion.x << ", Letra B, " << event.motion.y << '\n';
          
          if ((event.motion.x >= 875 and event.motion.x <= 935) and (event.motion.y >= 20 and event.motion.y <= 110))
            std::cout << event.motion.x << ", Letra C, " << event.motion.y << '\n';
          
          if ((event.motion.x >= 953 and event.motion.x <= 1013) and (event.motion.y >= 20 and event.motion.y <= 110))
            std::cout << event.motion.x << ", Letra D, " << event.motion.y << '\n';
          
          if ((event.motion.x >= 1030 and event.motion.x <= 1060) and (event.motion.y >= 20 and event.motion.y <= 110))
            std::cout << event.motion.x << ", Letra E, " << event.motion.y << '\n';
        
        break;

        case SDL_MOUSEBUTTONDOWN:
  
          std::cout << "Mouse button pressed\n";
  
          break;

      default:
      
        break;
     }
    }

  void clear() const
  {
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer,255, 255, 255, 255);
    SDL_RenderClear(renderer);
  }
  
  static SDL_Renderer * renderer;

  inline bool is_closed() const { return closed; }
  
  private:
    std::string title;
    
    int width;
    
    int height;
    
    bool closed;
    
    SDL_Window * window = nullptr;
};

SDL_Renderer * Window::renderer = nullptr;

class Rectangle
{
  public:
    Rectangle(int w, int h, int x, int y, std::string p) :
    width(w), height(h), x_pos(x), y_pos(y), path(p)
    {
      surface = IMG_Load(path.c_str());
      if (!surface)
        std::cerr <<"Failed to load surface\n";
        
      texture = SDL_CreateTextureFromSurface(Window::renderer,surface);
      if (!texture)
        std::cerr<< "Failed to create texture\n";
     
        SDL_FreeSurface(surface);
    }
    
    void draw() const
    {
      SDL_Rect rect = {x_pos, y_pos, width, height};
      
      if (texture)
        SDL_RenderCopy(Window::renderer,texture, nullptr, & rect);
        
      else 
      {       
        SDL_SetRenderDrawColor(Window::renderer,255,255,255,0);
        SDL_RenderFillRect(Window::renderer, & rect);
      }        
    }
    
    void events(SDL_Event & event)
    {
       if (event.type == SDL_KEYDOWN)
       {  
         switch (event.key.keysym.sym)
         {
           case SDLK_LEFT:
             x_pos -= 4;
             break;
           case SDLK_RIGHT:
             x_pos += 4;
             break;
           case SDLK_UP:
             y_pos -= 4;
             break;
           case SDLK_DOWN:
             y_pos += 4;
             break;
          }

       }
    }
    
    ~Rectangle()
    {
      SDL_DestroyTexture(texture);
    }
    

  protected:
  
    int width;
 
    int height;
    
    int y_pos;
    
    int x_pos;
    
    std::string path;
    
    SDL_Surface * surface = nullptr;
    
    SDL_Texture * texture = nullptr;
};

 void poll_events(Window & window, Rectangle & rect)
  {
    SDL_Event event;
    
    if (SDL_PollEvent(&event))
    {
      rect.events(event);
      window.events(event);
    
    }
   }
   
    void poll_events_Win(Window & window)
  {
    SDL_Event event;
    
    if (SDL_PollEvent(&event))
    {
      window.events(event);
    
    }
   }

int main()
{
  Window window("Test", 1200, 1026);

  Rectangle rect1(800,1026, 0, 0, "include/images/BOARD.png");

  Rectangle rect2(400,1026, 800, 0, "include/images/ALL.png");

  SDL_Event event;

  while (!window.is_closed())
  {
    poll_events_Win(window);
    rect1.draw();
    rect2.draw();
    window.clear();
  }
  return 0;
}
