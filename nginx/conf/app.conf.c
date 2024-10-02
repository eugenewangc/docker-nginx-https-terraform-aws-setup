server {
     listen 80;
     listen [::]:80;

     server_name eugene.wang www.eugene.wang; 
     server_tokens off;

     location /.well-known/acme-challenge/ {
          root /var/www/certbot;
     }
     location / {
          return 301 https://$host$request_uri;
     }
} 


server {
     listen 443 default_server ssl;
     listen [::]:443 ssl;
     server_name eugene.wang www.eugene.wang;

     # root /var/www/html;
     # index index.html index.htm index.nginx-debian.html;

     ssl_certificate /etc/letsencrypt/live/eugene.wang/fullchain.pem;
     ssl_certificate_key /etc/letsencrypt/live/eugene.wang/privkey.pem;

     include /etc/letsencrypt/options-ssl-nginx.conf;
     ssl_dhparam /etc/letsencrypt/ssl-dhparams.pem;


     location / {
          # proxy_pass http://eugene.wang;
          # try_files $uri $uri/ =404;

          root /var/www/html;
          index index.nginx-debian.html;
     }

}