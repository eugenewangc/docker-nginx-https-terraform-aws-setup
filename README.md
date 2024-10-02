# docker-nginx-https-terraform-aws-setup

## On Local Machine w/ Terraform and AWS CLI installed ##

#### SPIN UP AWS EC2 RESOURCE ####
terraform init <br/>
terraform apply

## On EC2 Instance Shell: ##

#### COPY REQUIRED FILES TO EC2 INSTANCE ####
- docker-compose.yml
- html/index.nginx-debian.html
- nginx/conf/app.conf
- init-letsencrypt.sh

#### MODIFY PARAMS: DOMAIN, EMAIL IN FILES ####
eugene.wang -> yourdomain.com <br/>
contact@eugene.wang -> mail@yourdomain.com
- nginx/conf/app.conf
- init-letsencrypt.sh <br/>


#### INSTALL DOCKER ON EC2 INSTANCE ####
sudo apt-get update<br/>
sudo apt-get install ca-certificates curl<br/>
sudo install -m 0755 -d /etc/apt/keyrings<br/>
sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg -o /etc/apt/keyrings/docker.asc<br/>
sudo chmod a+r /etc/apt/keyrings/docker.asc<br/>
echo \<br/>
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/ubuntu \<br/>
  $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \<br/>
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null<br/>
sudo apt-get update<br/>
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin<br/>

#### RUN BASH SCRIPT ####
sudo chmod +x init-letsencrypt.sh <br/>
sudo ./init-letsencrypt.sh