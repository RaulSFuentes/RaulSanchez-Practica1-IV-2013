<?php
class subearchivo{

		protected $archivo;
		protected $propiedades=array('nombre'=>null,'tipo'=>null,'tamanho'=>null,'nombretmp'=>null);
		
		
		function __construct(){
				$n=func_num_args();
				if($n>0){				
					$this->archivo[]=func_get_arg(0);
				}else {
					$this->archivo[]="archivo";
					};
			}		
		
		function __set($nombre,$valor){
				if(array_key_exists($nombre, $this->propiedades)){
						$this->propiedades[$nombre]=$valor;
					}else if($nombre =='texto') {
							$this->texto=$valor;
						}else {
						echo "No existe esa propiedad";
						}
			}
			
		function __get($nombre){
				if(array_key_exists($nombre, $this->propiedades)){
						return $this->propiedades[$nombre];
					}else if($nombre =='texto') {
							return $this->texto;
						}else {
						echo "No existe esa propiedad";
						}
			}
			function sube() {
							copy($this->nombretmp, "./imagenes/".$this->nombre);
			}
			function elimina(){
							unlink("./imagenes/".$this->nombre);
			}
};
?>