rmdir /S /Q Debug
rmdir /S /Q ipch
rmdir /S /Q Release
del /F /S GameEngine.sdf
del /F /S /A:H GameEngine.suo
rmdir /S /Q MathEngine\Debug
rmdir /S /Q MathEngine\Release
rmdir /S /Q Graphics\Debug
rmdir /S /Q Graphics\Release
rmdir /S /Q FileSystem\Debug
rmdir /S /Q FileSystem\Release