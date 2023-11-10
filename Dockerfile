# Stage 1: Build Python and PyTorch
FROM python:3.10-slim-buster AS build-python
WORKDIR /src
COPY requirements.txt .
RUN pip install --trusted-host pypi.python.org -r requirements.txt
ENV TORCH_VERSION=1.9.0+cpu
ENV TORCHVISION_VERSION=0.10.0+cpu
RUN pip install torch==$TORCH_VERSION torchvision==$TORCHVISION_VERSION -f https://download.pytorch.org/whl/cu111/torch_stable.html

# Stage 2: Build C++ and C#
FROM mcr.microsoft.com/dotnet/sdk:6.0 AS build-cpp-cs
WORKDIR /src
COPY . .
RUN apt-get update && apt-get install -y g++ && \
    g++ -o physics_engine physics_engine.cpp && \
    dotnet build unity_build.csproj

# Stage 3: Combine Python, PyTorch, C++, and C#
FROM python:3.10-slim-buster
WORKDIR /src
COPY --from=build-python /src /src
COPY --from=build-cpp-cs /src/phy_engine /src
COPY --from=build-cpp-cs /src/bin/Debug/net6.0/ /src
EXPOSE 80
ENV NAME Graphyti
CMD ["python", "src.py"]
