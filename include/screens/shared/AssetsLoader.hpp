#ifndef ASSETS_LOADER_HPP
#define ASSETS_LOADER_HPP

#include <string>
#include <memory>
#include <map>
#include "raylib.h"

class AssetsLoader {
    private:
        static std::shared_ptr<AssetsLoader> instance;

        std::map<std::string, Texture2D> images;
        std::map<std::string, Font> fonts;        

        /**
         * @brief Default constructor.
         */
        AssetsLoader();
    public:
        /**
         * @brief Destroy the Assets Loarder and unload all assets.
         */
        virtual ~AssetsLoader();

        /**
         * @brief Load a certain image from it's path if it's not already loaded.
         * 
         * @param path is the path to the asset.
         * 
         * @return A Texture2D copy object from the loaded asset.
         */
        Texture2D loadImage(const std::string path);

        /**
         * @brief Load a certain font from it's path if it's not already loaded.
         * 
         * @param path is the path to the asset.
         * 
         * @return A Font copy object from the loaded asset.
         */
        Font loadFont(const std::string path);

        /**
         * @brief Get the instance of the Assets Loader.
         * 
         * @return The instance of the Assets Loader.
         */
        static std::shared_ptr<AssetsLoader> getAssetLoader();
    
    private:
        /**
         * @brief Unload all images that was loaded in the images map.
         */
        void unloadImages();

        /**
         * @brief Unload all fonts that was loaded in the fonts map.
         */
        void unloadFonts();
};

#endif
